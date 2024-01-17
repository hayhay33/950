#!/usr/local/bin/python

headerFile = "header.txt"
footerFile = "footer.txt"

outputFile = "mymap.html"

with open(headerFile, 'r') as header:
    headerLines = header.read()

    header.close()
    
    with open(footerFile, 'r') as footer:
        footerLines = footer.read()

        footer.close()
        
        with open(outputFile, 'w') as mymap:

            # If you want to get super fancy, you can search the headerLines to
            # find the "center" point and change that, so that your map will
            # be centered perfectly, but you don't have to.

            mymap.write(headerLines)

            #-------------------------------------------------------------------
            # Your code goes here !!!
            
            mymap.write("        var marker = new google.maps.Marker({\n")
            mymap.write("           position: new google.maps.LatLng(42.3,-85.3),\n")
            mymap.write("           icon: pinImageR,\n")
            mymap.write("           map: map\n")
            mymap.write("        });\n")

            #-------------------------------------------------------------------
            
            mymap.write(footerLines)

            mymap.close()


            
