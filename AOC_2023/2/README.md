# Notes

## 2-1
There were major plans for this solution that involved structs, one of which was [embedded](https://gobyexample.com/struct-embedding). In the end, this 80 lines of code that just uses strings.Split() over and over gets the job done pretty well. 

To-do: Look at solution to "read" string for integer values instead of using hard codes array indexes. 

## 2-2

Maps prove useful yet again. In this case I think they are a little simpler to use resource wise since we always know we are looking up one of three existing colors keys and corresponding value. Not sure I'd want to use this with a larger set of keys.