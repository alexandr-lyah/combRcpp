# This script uses httr to download data from Google's API
# Notice ther is a limit of 2,500 calls per day

library(httr)
base_url <- "http://maps.google.com/maps/api/geocode/json"

geoCode <- function(address,verbose=FALSE) {
  r <- GET(base_url, query = list(address = address, sensor = "false"))
  stop_for_status(r)
  
  result <- content(r)
  if (!identical(result$status, "OK")) {
    warning("Request failed.", call. = FALSE)
    return(c(NA,NA,NA, NA))
  }

  first <- result$results[[1]]
  list(
    lat = first$geometry$location$lat,
    lng = first$geometry$location$lng,
    type = first$geometry$location_type,
    address = first$formatted_address
  )
}

# Test with a single address
geoCode("6100 Main Street, Houston, TX")