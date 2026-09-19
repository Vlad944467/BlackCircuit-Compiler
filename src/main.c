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
#include "compile.h"
#include <string.h>
#include <stdlib.h>
#include <stdint.h>
char s2[90];
int pos = 0;
uint8_t code[10000];
char arg1[20] = {0}, arg2[20] = {0}, arg3[20] = {0}, arg4[20] = {0};
char arg5[20] = {0};
void emit_byte(unsigned char b) {
    code[pos++] = b;
}
void compile(const char *line){
    strcpy(s2, line);
    int n = sscanf(s2, "%19s %19s %19s %19s %19s", arg1,arg2,arg3,arg4,arg5);
    if (n == 0) {
    return;
    }
    if (n < 1) {
    fprintf(stderr, "Ошибка парсинга строки: '%s'\n", s2);
    return;
    }
    else if(strcmp(arg1,"mov")==0) { mov(); }
    else if(strcmp(arg1,"sub")==0) { sub(); }
    else if(strcmp(arg1,"add")==0) { add(); }
    else if(strcmp(arg1,"hlt")==0) { emit_byte(0xF4); }
    else if(strcmp(arg1,"cmp")==0) { cmp(); }
    else if(strcmp(arg1,"alw")==0){ alw(); }
    else if(strcmp(arg1,"chr")==0){ chr(); }
    else if(strcmp(arg1, "eq")==0){ eq(); }
    else if(strcmp(arg1, "more")==0){ more(); }
    else if(strcmp(arg1, "less")==0){ less(); }
    else if(strcmp(arg1, "ne")==0){ ne(); }
    else if(strcmp(arg1, "intr")==0){ intr(); }
    else if(strncmp(s2, "REM", 3) == 0) return;
    else if(strcmp(arg1,"mul")==0){
    mul();
    }else {
        printf("Неизвестная команда: '%s' (строка: '%s')\n", arg1, s2);
    }

}
int main() {
    char line[256];
    FILE *in = fopen("programm_.bc","r");
    if (!in) {
        perror("Не удалось открыть входной файл");
        return 1;
    }

    while (fgets(line, 256, in)) {
        compile(line);
    }
    fclose(in);

    FILE *out = fopen("programm_.bin","wb");
    fwrite(code, 1, pos, out);
    fclose(out);

    printf("Готово: programm_.bin (%d байт)",pos);
    return 0;
}
