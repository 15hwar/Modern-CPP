cat data.dat | wc -l
grep -c 'd[ao]lor' data.dat
cat data.dat| wc -w
cat data.dat | tr ' ' '\n' | grep ^mol | wc -l      # tr ' ' '\n', convert each ' ' into new line