date = read.table("data.txt")
date

sumX = sum(file$V1) 
sumY = sum(file$V2) 
sumXX = sum(file$V1*file$V1)
sumXY = sum(file$V1*file$V2) 

A = matrix(data = c(sumXX, sumX, sumX, length(date$V1)), nrow = 2, ncol = 2)
f = c(sumXY, sumY)
ab = solve(A, f)

#коэффициенты
#a
ab[1]
#b
ab[2]

#прогнозируеый уровень инфляции
ab[1]*4.8+ab[2]


#проверка стандартной функцией
lm(date$V2 ~ date$V1)
