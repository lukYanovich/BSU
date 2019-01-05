#задание 1

library(cluster)

x1 = runif(100, 0, 100)
y1 <- rnorm(n = 100, mean = 0, sd = 0.5)

x2 = rnorm(n = 100, mean = 0, sd = 0.5)
y2 = runif(100, 0, 100)

A <- rbind(matrix(c(x1, x2), ncol = 2), matrix(c(y1, y2), ncol = 2))
colnames(A) <- c("x", "y")
cl = clara(A, 4)
plot(cl)
plot(A, col=cl$clustering, xlab = "x", ylab = "y")


#задание 2

data(votes.repub)
plot(agnes(votes.repub))
