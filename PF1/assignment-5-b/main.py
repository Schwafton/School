def main():

# Starting URL
    url_str = "https://www.ussgs.gov/about/about-us"

# Print a line of stars using repition operator
    print('*' * 70, end = "\n\n")

# Print the length of the url
    print("The length of the URL is", len(url_str), end="\n\n")

# Statement prints if "ussgs" is found in the URL
    if "ussgs" in url_str:
      print("Found it.  ussgs is in there!", end="\n\n")

# Print URL with "ussgs" replaced by "usgs"
    print("Now changed to usgs:", url_str.replace("ussgs", "usgs"), end="\n\n")

# Print slice of URL   
    url_slice = slice(-8, -3, 1)
    print("URL sliced from the 8th character from the end to the 3rd:", url_str[url_slice], end="\n\n")
    
# Print URL split at forward slashes
    print("URL split at the forward slash (/):", url_str.split("/"), sep="\n", end="\n\n")

# Print URL concatenated with "/who-we-are"
    print('Concatenated "/who-we-are" onto the string.  The new string is:', url_str+"/who-we-are", sep="\n", end="\n\n")

# Print another line of stas
    print('*' * 70)
    
main()
