Sys.setlocale(, "ru_RU")

generate <- function(m, a, c, range, x){
  v = x
  for (i in 1:range) {
    xNext = (a * x + c) %% m 
    v = c(v, xNext)
    x = xNext
  }
  print("математическое ожидание:")
  print(mean(v))
  print("идеальное:")
  print(m/2)
  
  print("дисперсия:")
  print(var(v))
  
  hist(v, breaks = 16, freq = FALSE, col = "lightblue",
       xlab = "вектор значений",
       ylab = "плотность вероятности",
       main = "гистограмма, совмещённая с кривой плотности")
  lines(density(v), col = "red", lwd = 2)
  
  return (v)
}
