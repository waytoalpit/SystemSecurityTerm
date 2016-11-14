#go to specific dir where we want to download files from server
cd /home/alpitgupta/systemsecurity

#rename the older server files
rename virus.txt virus.txt.old
rename whitelist.txt whitelist.txt.old

#download both virus and whitelist files from server
wget  https://raw.githubusercontent.com/waytoalpit/SystemSecurityTerm/master/virus.txt
wget  https://raw.githubusercontent.com/waytoalpit/SystemSecurityTerm/master/whitelist.txt
