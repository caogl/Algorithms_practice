// Cracking the coding interview 17.9
// Question: Design a method to find the frequency of occurrences of any given word in a book.

/*
The first question that you should askyourinterviewer is if you'll be doing this operation once or repeatedly. 
That is, are you simply asking for the frequency of "dog," or might you askfor"dog,"and then "cat,""mouse,"and soon?

Solution (1): SingleQuery
In this case, we simply go through the book, word by word, and count the number of times that a word appears.
This will take 0(n) time. We know we can't do better than that since we must look at every word in the book.

--> while traversing, keep two position change and keep track of the nearest --O(words number)


Solution (2): Repetitive Queries
If we're doing the operation repeatedly, then we can probably afford to take some time and extra memory to do 
pre-processing on the book. We can create a hash table which maps from a word to its frequency. 
The frequency of any word can be easily looked up in 0(1) time. 

--> When query, do a merge sort like method and update the smallest distance --O(frequency(word1)+ frequency(word2))
