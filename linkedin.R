library(httr)
library(jsonlite)

find_endorsements <- function(x) {
  r <- GET("https://www.linkedin.com/ta/skill" ,query = list(query = x))
  stop_for_status(r)
  
  json <- content(r, "parsed")
  
  vapply(json$resultList, "[[", "displayName", FUN.VALUE = character(1))
}

find_endorsements("java")