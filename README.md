# School Schedule to iCalendar Converter

This C program converts school schedules from web files (e.g., HTML) into the .ics format, making them compatible with iCalendar anad Google Calendar. It provides student s with a convenient way to manage their semester schedules efficiently.

## Features *still a draft, subject to change*

- **User Authentication**: Users must sign in to access the tool via a web page or Android application.
- **Event Management**: Users can input events or tasks, including details such as name, start time, duration, location, and priority.
- **Schedule Optimization**: The application uses Google Maps/Transit information to optimize the schedule, considering travel times between event locations.
- **Schedule Modification**: Users can modify the optimized schedule if required.
- **Persistent Storage**: The schedule is saved to a central server and can be accessed later or printed out.
- **Dynamic Recalculation**: If the user cannot meet the schedule, the application recalculates to accommodate changes.
- **Priority Management**: In case of a full day, lower priority tasks are dropped in favor of higher priority ones.
- **Performance Tracking**: The application tracks the percentage of missed events to encourage task completion.

## Getting Started

### Prerequisites

- A C compiler (e.g., GCC)
- Standard C libraries for file I/O and string manipulation

### Installation *NOT APPROVED / STABLE* as this is a draft

Clone the repository:

```bash
git clone https://github.com/yourusername/school-schedule-to-icalendar.git
```

Compile the program:

```bash
gcc -o schedule_converter main.c core_functions.c course_parser.c -I.
```

## Usage

### Command Line Interface

Import a schedule:

```bash
./schedule_converter import path/to/schedule.txt
```

Export a schedule:

```bash
./schedule_converter export path/to/output.ics
```

View the schedule:

```bash
./schedule_converter view
```

### Graphical User Interface *Same goes for this*

Run the program without arguments to launch the GUI:

```bash
./schedule_converter
```

## Project Structure - definately not set in stone, very rough draft. 

- `main.c`: Main program entry point.
- `core_functions.c/h`: Core functionalities for importing, exporting, and viewing schedules.
- `course_parser.c/h`: Module for parsing course schedules from text files.
- `gui_interface/dashboard.c/h`: GUI components and functionalities.

## Contributors - INCLUDE after approval from group members 

## License

This project is licensed under the MIT License - see the [LICENSE.md](LICENSE.md) file for details.

## Acknowledgments

- Sheridan College for providing the course schedule data format.
