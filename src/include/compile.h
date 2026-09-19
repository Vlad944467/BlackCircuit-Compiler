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
#ifndef COMPILE_H
#define COMPILE_H
#include <stdint.h>
void mov();
void sub();
void add();
void cmp();
void alw();
void chr();
void eq();
void more();
void less();
void ne();
void intr();
void mul();
extern char arg1[20], arg2[20], arg3[20], arg4[20];
extern char arg5[20];
extern uint8_t code[10000];
extern int pos;
void emit_byte(unsigned char b);
extern char s2[90];
void compile(const char *line);
#endif
