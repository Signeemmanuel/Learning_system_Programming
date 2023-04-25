#! /bin/bash

func1()
{
	#declare sets the variable scope to local within the function

	declare localName="Josue"
	globalName="Emmanuel"

	echo "In func1 name: " $localName " " $globalName
}

func2()
{
	func1
	echo "In func2 name: " $localName " " $globalName
}

func2

