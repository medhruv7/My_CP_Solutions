from datetime import *

ans = 0
year = 1901
month = 1

# the day on 1st of that month
dayi = date(year,month,1)

while dayi.year < 2001 :
	#which day of week is that date
	if dayi.weekday() == 6 :
		ans += 1
	if month + 1 == 13 :
		month = 1
		year += 1
	else :
		month += 1
	dayi = date(year,month,1)
	
print(ans)
