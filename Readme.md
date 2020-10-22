# Generic Table View
## Idea
When having generic properties the user can extend, it is usefull to store them into a table. Each property has it's own datatype and limits. To solve this problem, a generic table view is created where it can be choosen how the data should be modified.
Use the example to test the functionality.

## Usage
Add this repository as submodule into your project and set the paths to the headers and source files

## Add your own widgets
If you would like to use different widget to modify the properties, derive your widget from **PropertySelectionWidget** and implement all the required methods. Add two members to your class which stores the current value and one which stores the widget which is used to modify the property.

## TODO:
- use smartpointers instead of classic pointers, because otherwise it is difficult to track if the widget still exists or was already deleted.
