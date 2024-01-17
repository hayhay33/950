headerFile = 'header.txt';
footerFile = 'footer.txt';

outputFile = 'mymap.html';

mymap = fopen(outputFile,'w');

header = fopen(headerFile);
while ~feof(header)
  headerLine = fgetl(header);
  fprintf(mymap,'%s\n',headerLine);
end
fclose(header);

fprintf(mymap,'var marker = new google.maps.Marker({\n');
fprintf(mymap,'   position: new google.maps.LatLng(42.3,-85.3),\n');
fprintf(mymap,'   icon: pinImageR,\n');
fprintf(mymap,'   map: map\n');
fprintf(mymap,'})');

footer = fopen(footerFile);
while ~feof(footer)
  footerLine = fgetl(footer);
  fprintf(mymap,'%s\n',footerLine);
end
fclose(footer);


fclose(mymap);



