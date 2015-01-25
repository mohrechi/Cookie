package main

import "fmt"

func main() {
	var q int
	fmt.Scan(&q)
	nameMap := make(map[string]string)
	for ; q > 0; q-- {
		var oldName, newName string
		fmt.Scan(&oldName, &newName)
		oldest, exists := nameMap[oldName]
		if exists {
			delete(nameMap, oldName)
			nameMap[newName] = oldest
		} else {
			nameMap[newName] = oldName
		}
	}
	fmt.Println(len(nameMap))
	for newName, oldName := range nameMap {
		fmt.Println(oldName + " " + newName)
	}
}
