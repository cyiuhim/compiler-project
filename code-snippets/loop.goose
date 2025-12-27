## this is the example of a for loop, index-based

for {i <- [2..5]| 
honk <<vec(i)>>.
}

## this is the example of a for loop, element-based

for {n <- vec|
honk <<n>>.
}
