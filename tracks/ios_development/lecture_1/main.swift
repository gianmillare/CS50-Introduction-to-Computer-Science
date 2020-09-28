//
//  main.swift
//  lecture_1
//
//  Created by Gian Millare on 9/27/20.
//

import Foundation

//to create a class, assign values and use a struct (init) to assign the values to itself
class Track {
    let name: String
    let instructor: String
    
    init(name: String, instructor: String) {
        self.name = name
        self.instructor = instructor
    }
}

//create a list using the class above
let tracks: [Track] = [
    Track(name: "Mobile", instructor: "Tommy"),
    Track(name: "Web", instructor: "Brian"),
    Track(name: "Games", instructor: "Colton")
]

//create a list or array
let students = ["Harry", "Ron", "Hermione"]

// to create an empty dictionary, use [:]. Note that the key is a string and the value is a class
var assignments: [String : Track] = [:]

//to create a random placement, use Int.random and specify the range 0 ..< #value
for student in students {
//    assign a random integer to a variable
    let track = Int.random(in: 0 ..< tracks.count)
//    append into the dictionary the name of the student and a track --> list[index]
    assignments[student] = tracks[track]
}

//print the dictionary
for (student, track) in assignments {
    print("\(student) got \(track.name) with \(track.instructor)")
}
