touch ../week1/file.txt
echo Sergeev Nikita > ../week1/file.txt
link ../week1/file.txt  _ex2.txt
find .. -inum $(ls -i ../week1/file.txt | awk '{print $1}') > ex2.txt
find .. -inum $(ls -i ../week1/file.txt | awk '{print $1}') -exec rm {} \;
