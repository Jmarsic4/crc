/*
5-LEVEL hysteresis implementation
josko.marsic@gmail.com
*/
#include <stdio.h>


unsigned int hysteresis(unsigned int );
 
int main () {

  unsigned int i=0;

  for (i=0;i<100;i++)  
    printf("%d,- %d\n",i,hysteresis(i));
  
  for (i=100;i>0;i--)  
    printf("%d,- %d\n",i,hysteresis(i));
  
  return 0;  
}  
  
unsigned int hysteresis(unsigned int input_percent)
{

    static unsigned int current_discrete_level=0;
       

    if(input_percent<=10)
    { 
        current_discrete_level=0;
    }
    else if( (input_percent<15))
    {
        if(current_discrete_level==0)
            current_discrete_level=0;
        else
            current_discrete_level=1;           
    }
    
    
    else if( (input_percent<=35))
    {    
        current_discrete_level=1;            
    }
    else if( (input_percent<40))
    {
        if(current_discrete_level<=1)
            current_discrete_level=1;
        else
            current_discrete_level=2;           
    }    
    
    
    else if( (input_percent<=60))
    {    
        current_discrete_level=2;            
    }
    else if( (input_percent<65))
    {
        if(current_discrete_level<=2)
            current_discrete_level=2;
        else
            current_discrete_level=3;           
    }        
    
    
    else if( (input_percent<=85))
    {    
        current_discrete_level=3;            
    }
    else if( (input_percent<90))
    {
        if(current_discrete_level<=3)
            current_discrete_level=3;
        else
            current_discrete_level=4;           
    }
    else
            current_discrete_level=4;      
    
   
    return current_discrete_level;
    
}

/*
0,- 0
1,- 0
2,- 0
3,- 0
4,- 0
5,- 0
6,- 0
7,- 0
8,- 0
9,- 0
10,- 0
11,- 0
12,- 0
13,- 0
14,- 0
15,- 1
16,- 1
17,- 1
18,- 1
19,- 1
20,- 1
21,- 1
22,- 1
23,- 1
24,- 1
25,- 1
26,- 1
27,- 1
28,- 1
29,- 1
30,- 1
31,- 1
32,- 1
33,- 1
34,- 1
35,- 1
36,- 1
37,- 1
38,- 1
39,- 1
40,- 2
41,- 2
42,- 2
43,- 2
44,- 2
45,- 2
46,- 2
47,- 2
48,- 2
49,- 2
50,- 2
51,- 2
52,- 2
53,- 2
54,- 2
55,- 2
56,- 2
57,- 2
58,- 2
59,- 2
60,- 2
61,- 2
62,- 2
63,- 2
64,- 2
65,- 3
66,- 3
67,- 3
68,- 3
69,- 3
70,- 3
71,- 3
72,- 3
73,- 3
74,- 3
75,- 3
76,- 3
77,- 3
78,- 3
79,- 3
80,- 3
81,- 3
82,- 3
83,- 3
84,- 3
85,- 3
86,- 3
87,- 3
88,- 3
89,- 3
90,- 4
91,- 4
92,- 4
93,- 4
94,- 4
95,- 4
96,- 4
97,- 4
98,- 4
99,- 4
100,- 4
99,- 4
98,- 4
97,- 4
96,- 4
95,- 4
94,- 4
93,- 4
92,- 4
91,- 4
90,- 4
89,- 4
88,- 4
87,- 4
86,- 4
85,- 3
84,- 3
83,- 3
82,- 3
81,- 3
80,- 3
79,- 3
78,- 3
77,- 3
76,- 3
75,- 3
74,- 3
73,- 3
72,- 3
71,- 3
70,- 3
69,- 3
68,- 3
67,- 3
66,- 3
65,- 3
64,- 3
63,- 3
62,- 3
61,- 3
60,- 2
59,- 2
58,- 2
57,- 2
56,- 2
55,- 2
54,- 2
53,- 2
52,- 2
51,- 2
50,- 2
49,- 2
48,- 2
47,- 2
46,- 2
45,- 2
44,- 2
43,- 2
42,- 2
41,- 2
40,- 2
39,- 2
38,- 2
37,- 2
36,- 2
35,- 1
34,- 1
33,- 1
32,- 1
31,- 1
30,- 1
29,- 1
28,- 1
27,- 1
26,- 1
25,- 1
24,- 1
23,- 1
22,- 1
21,- 1
20,- 1
19,- 1
18,- 1
17,- 1
16,- 1
15,- 1
14,- 1
13,- 1
12,- 1
11,- 1
10,- 0
9,- 0
8,- 0
7,- 0
6,- 0
5,- 0
4,- 0
3,- 0
2,- 0
1,- 0

*/
