/**
 * task3swift.swift
 * Hannah Soria
 * 4/25/2024
 * examples of swift handling reading and writing to files
 * 
 */

 import Foundation

 enum FileError: Error {
    case fileNotFound
    case fileReadError
    case fileWriteError
 }

// read function with error handling
func read() throws -> String {
    guard let fileContents = try? String(contentsOfFile: "wctst.txt") else{
        throw FileError.fileNotFound
    }
    return fileContents
}

// write function with error handling
func write() throws {
    let content = "hello world"
    do {
        try content.write(toFile: "output.txt", atomically: true, encoding: .utf8)
    } catch {
        throw FileError.fileWriteError
    }
}

// do catch error handling for read
do {
    let fileContents = try read()
    print(fileContents)
} catch FileError.fileNotFound {
    print("Error: no file found")
} catch {
    print("Error: read file error", error)
}

// do catch error handling for write
do {
    try write()
    print("file write successful")
} catch FileError.fileWriteError {
    print("Error: write file error")
} 