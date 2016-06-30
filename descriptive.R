library(purrr)

funs <- list(median, mean, sd)

funs %>%
map(~ mtcars %>% map_dbl(.x))