<h2 align="center">
Push Swap

</h2>
<h6 align="center">
sort data on a stack, with a limited set of instructions,  
using the lowest possible number of actions 📚. 
<br>
status: pass @ 42 lisboa 2021
<br>
by: mvaldeta
</h6>

<h2>
</h2>

|  |  |  |
|:---------:|:---------:|:---------:|
|![STACK3](https://64.media.tumblr.com/ac866c7d72f6f3a3958ae1a238038d88/tumblr_nyaxxsIIaQ1qblxj7o7_400.gifv)|![STACK3](https://64.media.tumblr.com/bcf49029014e8bbecf72e9c4a4ab6337/tumblr_nyaxxsIIaQ1qblxj7o3_400.gifv)|![STACK3](https://64.media.tumblr.com/84fbd5ff5b0a41347f7ad9de95dd534e/tumblr_nyaxxsIIaQ1qblxj7o10_400.gifv)|

###### Rules  
```
Create a ~Limited~ sorting algorithm with two stacks: A && B  
To do so, you only have the following operations at your disposal:  
```
- SA  : swaps the TOP 2 elements of A 🔄    
- SB  : swaps the TOP 2 elements of B 🔄    
- SS  : SA and SB at the same time  A🔄 B🔄 TOPS
- PA  : TOP A -> TOP B ➡️ 
- PB  : TOP B -> TOB A ⬅️
- RA  : rotates A ⤵️
- RB  : rotates B ⤵️ 
- RR  : rotates A ⤵️ + rotates B ⤵️ at the same time.
- RRA : rotates A ⤴️ 
- RRA : rotates B ⤴️  
- RRR : rotates A ⤴️ + rotates B ⤴️ at the same time.  

###### Limits of operations 
```
size of 3   : <= 3
size of 5   : < 12
size of 100 : < 900
size of 500 : < 8500
```
###### Approach Size <= 3 
```
handle individual cases of 2 and 3 in separate modules to be re-used later
```
###### Approach Size <= 5 
```
find median, split into A or B, if a stack has size of 2 or 3 fetches the modules previously outlined to solve
```
###### Approach Size <= 100 (I started at 60 just because)
```
pass all elements fromm stack A to B, and to insertion sort from B to A
```
###### Approach Size <= 500 
```
pass all elements from stack A to B, this time within a range: first chunks of the smallest increasing to the largests. Chunk size depends on the initial stack size. If biger than 100 elements, markers for each chunk will be provided by: size / 25
```
###### Illustration 

| stack A | stack B |
|:---------:|:-----------------:|
| 83 |    |
| 31 |    |
| 19 |    |
| 52 |    |
| 82 |    |
| 96 |    |
| 66 |    |
| 23 |    |
| 34 |    |
| 4  |    | 
###### start

###### Research  

[Personal Log](https://docs.google.com/document/d/1BRx4uDb469BFj6pL2ozEluOIOzOkLMNUBLTMFMG50CU/edit?usp=sharing)  

[Peek](https://en.wikipedia.org/wiki/Peek_(data_type_operation))   

[Abtract data types](https://en.wikipedia.org/wiki/Abstract_data_type)

[Linus on Linked lists](https://github.com/mkirchner/linked-list-good-taste)  

