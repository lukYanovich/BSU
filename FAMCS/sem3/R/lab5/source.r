library(arules)

tr <- read.transactions("test.txt", format = "basket", sep = ",")
inspect(tr)
image(tr)
itemFrequencyPlot(tr, support = 0.5)
length(tr)
rules <- apriori(tr)
inspect(rules)
