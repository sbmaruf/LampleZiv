
There is a problem regarding this ppt.
First is when the string ends with no unique[non mathcing] substring then I have just put the index of the substring and mark it with '#' character. You can use any character hare which will never occur in the  dataset.


1.compress.cpp 
	Output compressed data;
	996 KB -> 954 KB
	95.3 MB -> 38.1 MB
	953 MB ->  64 MB [Pattern have much frequency].
	
2. Decrypt
	output original data
	954 KB -> 996 KB
	38.1 MB -> 95.3 MB
	64 MB - > 953 MB 

3. dataset
	this is the dataset generator. it's used for creating large volume of data.

here in.txt is the input dataset and re.txt is the output of the Decryptor.
all in->re , in1->re1 , in2->re2 are compared with linux diff function from terminal and do not found any error.