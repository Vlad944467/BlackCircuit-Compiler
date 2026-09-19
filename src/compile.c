/*
 * Copyright 2026 Vlad944467
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *     http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

#include <stdio.h>
#include <string.h>
#include "compile.h"
#include <stdlib.h>
#include <stdint.h>

void mov() {
    int num = atoi(arg3);
    if(strcmp(arg2, "a")==0) {
        emit_byte(0xB8);
    }
    else if(strcmp(arg2, "b")==0) {
        emit_byte(0xBB);
    }
    else if(strcmp(arg2, "c")==0) {
        emit_byte(0xB9);
    }
    else {
        fprintf(stderr, "Ошибка: неизвестный регистр '%s' в команде mov\n", arg2);
        return;
    }
    emit_byte(num & 0xFF);
    emit_byte((num >> 8) & 0xFF);
}
void sub() {
    int num = atoi(arg3);
    emit_byte(0x2D);
    emit_byte(num & 0xFF);
    emit_byte((num >> 8) & 0xFF);
}
void add() {
    int num = atoi(arg3);
    emit_byte(0x05);
    emit_byte(num & 0xFF);
    emit_byte((num >> 8) & 0xFF);
}
void cmp() {
    int num = atoi(arg3);
    emit_byte(0x3D);
    emit_byte(num & 0xFF);
    emit_byte((num >> 8) & 0xFF);
}
void alw() {
    int addr = atoi(arg2);
    emit_byte(0xEB);
    emit_byte(addr & 0xFF);
}
void chr() {
    char c = arg2[0];
    emit_byte(c);
    emit_byte(0);
}
void eq() {
    int addr = atoi(arg2);
    emit_byte(0x74);
    emit_byte(addr & 0xFF);
}
void more() {
    int addr = atoi(arg2);
    emit_byte(0x7F);
    emit_byte(addr & 0xFF);
}
void less() {
    int addr = atoi(arg2);
    emit_byte(0x7C);
    emit_byte(addr & 0xFF);
}
void ne() {
    int addr = atoi(arg2);
    emit_byte(0x75);
    emit_byte(addr & 0xFF);
}
void intr() {
    int addr = atoi(arg2);
    emit_byte(0xCD);
    emit_byte(addr & 0xFF);
}
void mul() {
    int num = atoi(arg3);
    emit_byte(0x69);
    emit_byte(0xC0);
    emit_byte(num & 0xFF);
    emit_byte((num >> 8) & 0xFF);
}
