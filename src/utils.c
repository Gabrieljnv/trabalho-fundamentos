#include "utils.h"
#include <stdio.h>
#include <string.h>
#include <time.h>
#include <stdlib.h>


static int parse_ymd(const char *s, struct tm *out) {
int y, m, d;
if (sscanf(s, "%d-%d-%d", &y, &m, &d) != 3) return -1;
memset(out, 0, sizeof(*out));
out->tm_year = y - 1900;
out->tm_mon = m - 1;
out->tm_mday = d;
return 0;
}


int data_valida(const char *date) {
struct tm t;
if (parse_ymd(date, &t) != 0) return 0;
time_t tt = mktime(&t);
return tt != (time_t)-1;
}


int diff_days(const char *date_start, const char *date_end) {
struct tm t1, t2;
if (parse_ymd(date_start, &t1) != 0) return -999;
if (parse_ymd(date_end, &t2) != 0) return -999;
time_t tt1 = mktime(&t1);
time_t tt2 = mktime(&t2);
if (tt1 == (time_t)-1 || tt2 == (time_t)-1) return -999;
double diff = difftime(tt2, tt1);
int days = (int)(diff / (60*60*24));
return days;
}