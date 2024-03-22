# GUI template for Flipper Zero


## State 
Currently the "app" has three scenes: 
 - One Widget View (defined in scenes/main_page.h)
 - Two Popup View  (defined in scenes/warning_page.h and scenes/happy_page.h)

The logic of switching between this three is not yet implemented.
It can be implemented in the individual ```_on_event()``` functions. 

## Build

- Clone this repo into a the firmware of your choice's ```applications_user``` directory
- Optional: Run ```ufbt vscode_dist``` to create a better developer experience in case if you're using VSC.
- Run ```ufbt``` to build this project
- Rename the APPID, entrypoint, icon ...  

## Requirements

- optional: ufbt (instead of ```fbt``` offered by the flipper's firmware)

## Sources and useful websites
- [Lopaka](https://lopaka.app/) : Web-based GUI builder from many platforms, including Flipper Zero
- [Flipper Zero - Part 1 - Creating UI using Scenes](https://www.youtube.com/watch?v=YbskaB6caqk)
