#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <wiringPi.h>

#define LCD_D4 2
#define LCD_D5 3
#define LCD_D6 1
#define LCD_D7 4
#define LCD_RS 7
#define LCD_EN 0
#define BT0 12
#define BT1 13
#define BT2 14
#define BT3 10
#define BT4 11
#define BT5 21
#define BT6 22
#define BT7 26
#define BT8 23
#define BT9 24
#define EQL 27
#define PLUS 5
#define MINUS 6

void write4bits(unsigned char command)
{
    digitalWrite(LCD_D4, (command & 1));
    command >>= 1;
    digitalWrite(LCD_D5, (command & 1));
    command >>= 1;
    digitalWrite(LCD_D6, (command & 1));
    command >>= 1;
    digitalWrite(LCD_D7, (command & 1));
    digitalWrite(LCD_EN, 1);
    delayMicroseconds(10);
    digitalWrite(LCD_EN, 0);
    delayMicroseconds(10);
}

void sendDataCmd4(unsigned char data)
{
    write4bits(((data >> 4) & 0x0f));
    write4bits((data & 0x0f));
    delayMicroseconds(100);
}

void putCmd4(unsigned char cmd)
{
    digitalWrite(LCD_RS, 0);
    sendDataCmd4(cmd);
}

void putChar(char c) {

    digitalWrite(LCD_RS, 1);

    sendDataCmd4(c);
}


void initialize_textlcd() {	//CLCD 초기화
    pinMode(LCD_RS, OUTPUT); pinMode(LCD_EN, OUTPUT);
    pinMode(LCD_D4, OUTPUT); pinMode(LCD_D5, OUTPUT);
    pinMode(LCD_D6, OUTPUT); pinMode(LCD_D7, OUTPUT);
    digitalWrite(LCD_RS, 0); digitalWrite(LCD_EN, 0);
    digitalWrite(LCD_D4, 0); digitalWrite(LCD_D5, 0);
    digitalWrite(LCD_D6, 0);  digitalWrite(LCD_D7, 0);

    pinMode(BT0, INPUT); pinMode(BT1, INPUT); pinMode(BT2, INPUT);
    pinMode(BT3, INPUT); pinMode(BT4, INPUT); pinMode(BT5, INPUT);
    pinMode(BT6, INPUT); pinMode(BT7, INPUT); pinMode(BT8, INPUT);
    pinMode(BT9, INPUT); pinMode(EQL, INPUT); pinMode(PLUS, INPUT);
    pinMode(MINUS, INPUT);

    pullUpDnControl(BT0, PUD_DOWN); pullUpDnControl(BT1, PUD_DOWN); pullUpDnControl(BT2, PUD_DOWN);
    pullUpDnControl(BT3, PUD_DOWN); pullUpDnControl(BT4, PUD_DOWN); pullUpDnControl(BT5, PUD_DOWN);
    pullUpDnControl(BT6, PUD_DOWN); pullUpDnControl(BT7, PUD_DOWN); pullUpDnControl(BT8, PUD_DOWN);
    pullUpDnControl(BT9, PUD_DOWN); pullUpDnControl(EQL, PUD_DOWN); pullUpDnControl(PLUS, PUD_UP);
    pullUpDnControl(MINUS, PUD_UP);
    delay(35);

    digitalWrite(PLUS, 0);  digitalWrite(MINUS, 0);

    putCmd4(0x28);  // 4비트 2줄
    putCmd4(0x28);
    putCmd4(0x28);
    putCmd4(0x0e); // 디스플레이온 커서 온
    putCmd4(0x02); // 커서 홈 
    delay(2);
    putCmd4(0x01); // 표시 클리어 
    delay(2);
}

int main(int argc, char** argv) {
    char buf1[100] = "Overflow";
    char buf2_1[100] = "Invalid";
    char buf2_2[100] = "Operation";
    char tmp[100] = "";
    char res_pr[100];
    int i; int len1 = strlen(buf1); int len2_1 = strlen(buf2_1); int len2_2 = strlen(buf2_2);
    int cnt = 0;
    int line = 0;
    int before_op = 1;
    int add = 0;
    int sub = 0;
    int result = 0;
    int reset = 0;

    wiringPiSetup();

    initialize_textlcd();
    while (1) {
        if (digitalRead(BT0) == HIGH) {
            if (reset) {
                reset = 0;
                add = 0;
                sub = 0;
                result = 0;
                before_op = 1;
                line = 0;
                cnt = 0;
                tmp[0] = '\0';
                initialize_textlcd();
            }
            strcat(tmp, "0");
            putChar('0');
            digitalWrite(BT0, 0);
            cnt += 1;
            before_op = 0;
            delay(200);
        }
        if (digitalRead(BT1) == HIGH) {
            if (reset) {
                reset = 0;
                add = 0;
                sub = 0;
                result = 0;
                before_op = 1;
                line = 0;
                cnt = 0;
                tmp[0] = '\0';
                initialize_textlcd();
            }
            strcat(tmp, "1");
            putChar('1');
            digitalWrite(BT1, 0);
            cnt += 1;
            before_op = 0;
            delay(200);
        }
        if (digitalRead(BT2) == HIGH) {
            if (reset) {
                reset = 0;
                add = 0;
                sub = 0;
                result = 0;
                before_op = 1;
                line = 0;
                cnt = 0;
                tmp[0] = '\0';
                initialize_textlcd();
            }
            strcat(tmp, "2");
            putChar('2');
            digitalWrite(BT2, 0);
            cnt += 1;
            before_op = 0;
            delay(200);
        }
        if (digitalRead(BT3) == HIGH) {
            if (reset) {
                reset = 0;
                add = 0;
                sub = 0;
                result = 0;
                before_op = 1;
                line = 0;
                cnt = 0;
                tmp[0] = '\0';
                initialize_textlcd();
            }
            strcat(tmp, "3");
            putChar('3');
            digitalWrite(BT3, 0);
            cnt += 1;
            before_op = 0;
            delay(200);
        }
        if (digitalRead(BT4) == HIGH) {
            if (reset) {
                reset = 0;
                add = 0;
                sub = 0;
                result = 0;
                before_op = 1;
                line = 0;
                cnt = 0;
                tmp[0] = '\0';
                initialize_textlcd();
            }
            strcat(tmp, "4");
            putChar('4');
            digitalWrite(BT4, 0);
            cnt += 1;
            before_op = 0;
            delay(200);
        }
        if (digitalRead(BT5) == HIGH) {
            if (reset) {
                reset = 0;
                add = 0;
                sub = 0;
                result = 0;
                before_op = 1;
                line = 0;
                cnt = 0;
                tmp[0] = '\0';
                initialize_textlcd();
            }
            strcat(tmp, "5");
            putChar('5');
            digitalWrite(BT5, 0);
            cnt += 1;
            before_op = 0;
            delay(200);
        }
        if (digitalRead(BT6) == HIGH) {
            if (reset) {
                reset = 0;
                add = 0;
                sub = 0;
                result = 0;
                before_op = 1;
                line = 0;
                cnt = 0;
                tmp[0] = '\0';
                initialize_textlcd();
            }
            strcat(tmp, "6");
            putChar('6');
            digitalWrite(BT6, 0);
            cnt += 1;
            before_op = 0;
            delay(200);
        }
        if (digitalRead(BT7) == HIGH) {
            if (reset) {
                reset = 0;
                add = 0;
                sub = 0;
                result = 0;
                before_op = 1;
                line = 0;
                cnt = 0;
                tmp[0] = '\0';
                initialize_textlcd();
            }
            strcat(tmp, "7");
            putChar('7');
            digitalWrite(BT7, 0);
            cnt += 1;
            before_op = 0;
            delay(200);
        }
        if (digitalRead(BT8) == HIGH) {
            if (reset) {
                reset = 0;
                add = 0;
                sub = 0;
                result = 0;
                before_op = 1;
                line = 0;
                cnt = 0;
                tmp[0] = '\0';
                initialize_textlcd();
            }
            strcat(tmp, "8");
            putChar('8');
            digitalWrite(BT8, 0);
            cnt += 1;
            before_op = 0;
            delay(200);
        }
        if (digitalRead(BT9) == HIGH) {
            if (reset) {
                reset = 0;
                add = 0;
                sub = 0;
                result = 0;
                before_op = 1;
                line = 0;
                cnt = 0;
                tmp[0] = '\0';
                initialize_textlcd();
            }
            strcat(tmp, "9");
            putChar('9');
            digitalWrite(BT9, 0);
            cnt += 1;
            before_op = 0;
            delay(200);
        }

        if (digitalRead(PLUS) == LOW) {
            if (before_op) {
                initialize_textlcd();
                for (i = 0; i < len2_1; i++) putChar(buf2_1[i]);
                putCmd4(0xC0);
                for (i = 0; i < len2_2; i++) putChar(buf2_2[i]);
                delay(2000);
                reset = 0;
                add = 0;
                sub = 0;
                result = 0;
                before_op = 1;
                line = 0;
                cnt = 0;
                tmp[0] = '\0';
                initialize_textlcd();
            }
            else {
                if (add) {
                    result += atoi(tmp);
                    add = 0;
                    sub = 0;
                }
                else if (sub) {
                    result -= atoi(tmp);
                    add = 0;
                    sub = 0;
                }
                else result = atoi(tmp);

                putChar('+');
                tmp[0] = '\0';
                add = 1;
                cnt += 1;
                before_op = 1;
                delay(200);
            }
            digitalWrite(PLUS, 0);
        }
        if (digitalRead(MINUS) == LOW) {
            if (before_op) {
                initialize_textlcd();
                for (i = 0; i < len2_1; i++) putChar(buf2_1[i]);
                putCmd4(0xC0);
                for (i = 0; i < len2_2; i++) putChar(buf2_2[i]);
                delay(2000);
                reset = 0;
                add = 0;
                sub = 0;
                result = 0;
                before_op = 1;
                line = 0;
                cnt = 0;
                tmp[0] = '\0';
                initialize_textlcd();
            }
            else if ((line == 0) && (cnt == 0)) {
                if (reset) {
                    reset = 0;
                    add = 0;
                    sub = 0;
                    result = 0;
                    before_op = 1;
                    line = 0;
                    cnt = 0;
                    tmp[0] = '\0';
                    initialize_textlcd();
                }
                strcat(tmp, "-");

                putChar('-');
                cnt += 1;
                before_op = 1;
                delay(200);
            }
            else {
                if (add) {
                    result += atoi(tmp);
                    add = 0;
                    sub = 0;
                }
                else if (sub) {
                    result -= atoi(tmp);
                    add = 0;
                    sub = 0;
                }
                else result = atoi(tmp);

                putChar('-');
                tmp[0] = '\0';
                sub = 1;
                cnt += 1;
                before_op = 1;
                delay(200);
            }
            digitalWrite(MINUS, 0);
        }

        if (digitalRead(EQL) == HIGH) {
            if (before_op) {
                initialize_textlcd();
                for (i = 0; i < len2_1; i++) putChar(buf2_1[i]);
                putCmd4(0xC0);
                for (i = 0; i < len2_2; i++) putChar(buf2_2[i]);
                delay(2000);
                reset = 0;
                add = 0;
                sub = 0;
                result = 0;
                before_op = 1;
                line = 0;
                cnt = 0;
                tmp[0] = '\0';
                initialize_textlcd();
            }
            else {
                if (add) result += atoi(tmp);
                else if (sub) result -= atoi(tmp);
                else result = atoi(tmp);

                sprintf(res_pr, "%d", result);
                putChar('=');
                cnt += 1;
                
                for (i = 0; i < strlen(res_pr); i++) {
                    putChar(res_pr[i]);
                    cnt += 1;

                    if (cnt >= 16) {
                        if (line == 0) {
                            putCmd4(0xC0);
                            line += 1;
                            cnt = 0;
                        }
                        else if (cnt >= 17) {
                            initialize_textlcd();
                            for (i = 0; i < len1; i++) putChar(buf1[i]);
                            delay(2000);
                            reset = 0;
                            add = 0;
                            sub = 0;
                            result = 0;
                            before_op = 1;
                            line = 0;
                            cnt = 0;
                            tmp[0] = '\0';
                            initialize_textlcd();
                            break;
                        }
                    }
                }
            }

            digitalWrite(EQL, 0);
            reset = 1;
            add = 0;
            sub = 0;
            result = 0;
            before_op = 1;
            line = 0;
            cnt = 0;
            tmp[0] = '\0';
            delay(200);
        }

        if (cnt >= 16) {
            if (line == 0) {
                putCmd4(0xC0);
                line += 1;
                cnt = 0;
            }
            else if(cnt >= 17) {
                initialize_textlcd();
                for (i = 0; i < len1; i++) putChar(buf1[i]);
                delay(2000);
                reset = 0;
                add = 0;
                sub = 0;
                result = 0;
                before_op = 1;
                line = 0;
                cnt = 0;
                tmp[0] = '\0';
                initialize_textlcd();
            }
        }
    }
}
