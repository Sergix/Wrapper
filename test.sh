./compile.sh $1
cd test
rm -f test.wrap
echo Hello World>info.txt
echo Hi me>info2.txt
mv ../build/linux/wrapper-linux-v$1 .
./wrapper-linux-v$1
rm info.txt
rm info2.txt
rm wrapper-linux-v$1
cd ..
