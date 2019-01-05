#вариант 8

#1.1


v <- scan(file = "date.txt", what = numeric())

#среднее значение 
mean(v)

#дисперсия 
var(v)

#минимальное
min(v)
    
#максимальное
max(v)

#стандартное отклонение
sd(v)

#квантили
quantile(v)

#мода
sort(unique(v))[which.max(table(v))]

#медиана
median(v)

#диаграма
m = matrix(v, nrow = 10, ncol = 5);
boxplot(m);

#проверяем элементы
k = 0;
for (i in 1:50)
  if (v[i]>=0 && v[i]<=0.5)
    k=k+1;
k

#общий статистический отчет
summary(v);



#1.2

#cut(x,breaks) — делит вектор на равные интервалы
v1 = table(cut(v,3.32*log(50) + 1));
barplot(v1);


#1.3


TABLE = read.table(file = "allcountries.txt", header = TRUE)
n1 = nrow(TABLE);
is.na(TABLE);
TABLE = na.omit(TABLE);
TABLE
n2 = nrow(TABLE);
#содержат строк с NA
n1-n2

min = 10^10
minI = 1;
for(i in 1:n2)
  if(min > TABLE$population[i]/TABLE$area[i]){
    min = TABLE$population[i]/TABLE$area[i]
    minI = i;
  }
#страна с наименьшей плотностью
TABLE$country[minI]
