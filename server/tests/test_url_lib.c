/*
 * Copyright (c) 2014 Netflix, Inc.
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions are met:
 *
 * Redistributions of source code must retain the above copyright notice, this
 * list of conditions and the following disclaimer.
 * Redistributions in binary form must reproduce the above copyright notice,
 * this list of conditions and the following disclaimer in the documentation
 * and/or other materials provided with the distribution.
 *
 * THIS SOFTWARE IS PROVIDED BY NETFLIX, INC. AND CONTRIBUTORS "AS IS" AND ANY
 * EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED
 * WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
 * DISCLAIMED. IN NO EVENT SHALL NETFLIX OR CONTRIBUTORS BE LIABLE FOR ANY
 * DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES
 * (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES;
 * LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND
 * ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
 * (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF
 * THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 */
#include <url_lib.h>
#include <dial_data.h>

#include <stdio.h>
#include <string.h>
#include <assert.h>
#include <ctype.h>
#include <tests/tap/basic.h>

static void test_smartstrcat() {
    char* src1 = "Hello ";
    char* src2 = "world!";
    char* src3 = " Trunc ated";
    char dest[128] = {0, };

    char* p = (char *) dest;
    p = smartstrcat(p, src1, 128);
    is_string("Hello ", dest, "1");
    p = smartstrcat(p, src2, dest + 128 - p);

    is_string("Hello world!", dest, "2");

    p = smartstrcat(p, src3, 6);
    is_string("Hello world! Trunc", dest, "3");
}

static void test_urldecode() {
    char* param = "%26bla+r";
    char dest[128] = {0, };

    ok(urldecode(dest, param, 128), "Failed to decode.");
    is_string("&bla r", dest, "Failed to decode.");
}

static void test_parse_app_name() {
    char *app_name;
    ok((app_name = parse_app_name(NULL)) != NULL, "Failed to extract app_name");
    is_string("unknown", app_name, "Failed to extract app_name");
    ok((app_name = parse_app_name("")) != NULL, "Failed to extract app_name");
    is_string("unknown", app_name, "Failed to extract app_name");
    ok((app_name = parse_app_name("/")) != NULL, "Failed to extract app_name");
    is_string("unknown", app_name, "Failed to extract app_name");
    ok((app_name = parse_app_name("/apps/YouTube/DialData")) != NULL,
           "Failed to extract app_name");
    is_string("YouTube", app_name, "Failed to extract app_name");
    ok((app_name = parse_app_name("//")) != NULL, "Failed to extract app_name");
    is_string("", app_name, "Failed to extract app_name");
    ok((app_name = parse_app_name("/invalid")) != NULL,
           "Failed to extract app_name");
    is_string("unknown", app_name, "Failed to extract app_name");
}

static void test_parse_params() {
    ok(!parse_params(""), "Empty query string should generate no params");
    ok(!parse_params(NULL), "Null query, should generate no params");

    DIALData *result = parse_params("a=b");
    is_string("a", result->key, "Wrong key");
    is_string("b", result->value, "Wrong value");

    result = parse_params("?a=b");
    is_string("a", result->key, "Wrong key");
    is_string("b", result->value, "Wrong value");

    result = parse_params("?a=b&c=d");
    is_string("c", result->key, "Wrong key");
    is_string("d", result->value, "Wrong value");
    is_string("a", result->next->key, "Wrong next key");
    is_string("b", result->next->value, "Wrong next value");

    char query_string[1024] = {0, };
    char *current = query_string;
    for (int i = 0; i < 25; ++i) {
        current = smartstrcat(current, "a=b&", 256);
    }
    result = parse_params(query_string);
    int length = 0;
    for (; result != NULL; result = result->next) {
        length++;
    }
    is_int(25, length, "25 params should have been parsed");
}

int main() {
    plan(28);
    test_smartstrcat();
    test_urldecode();
    test_parse_app_name();
    test_parse_params();
    return 0;
}
