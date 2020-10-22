# Generic Table View
Implements a generic table view where the cells can be modified by userdefined widgets. Use the example to test the functionality

## Usage
Add this repository as submodule into your project and set the paths to the headers and source files

## Add your own widgets
If you would like to use different widget to modify the properties, derive your widget from **PropertySelectionWidget** and implement all the required methods. Add two members to your class which stores the current value and one which stores the widget which is used to modify the property.

## TODO:
- use smartpointers instead of classic pointers, because otherwise it is difficult to track if the widget still exists or was already deleted.
