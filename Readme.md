# Generic Table View
## Idea
When having generic properties the user can extend, it is usefull to store them into a table. Each property has it's own datatype and limits. To solve this problem, a generic table view is created where it can be choosen how the data should be modified.
Use the example to test the functionality.

## Usage
- Add this repository as submodule into your project and set the paths to the headers and source files
- include all the Wrappers you need from the /lib/Wrapper folder into your project
- create a __GenericTableView__ and __GenericTableModel__ and set the model as model for the view (__GenericTableView::setModel()__)
- Add properties:
	- Create a new property __Property__
	- set wrapper you would like to use
	- append Property to model __GenericTableModel::appendProperty()__
- Remove properties: use __GenericTableModel::removeProperty()__ method

## Add your own widgets
If you would like to use different widget to modify the properties, derive your widget from __PropertySelectionWidget__ and implement all the required methods. Add two members to your class which stores the current value and one which stores the widget which is used to modify the property.

## Important
There is no check if the datatype is compatible with the widget! If you assign a value which datatype is not compatible with the widget, the value will not be set to the widget and you will not see any changes.

## TODO:

