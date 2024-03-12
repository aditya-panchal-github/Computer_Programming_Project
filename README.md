# School Schedule to iCalendar Converter

This C program converts school schedules from web files (e.g., HTML) into the .ics format, making them compatible with iCalendar anad Google Calendar. It provides student s with a convenient way to manage their semester schedules efficiently.

## Features *still a draft, subject to change*

Schedule Import: Users can import their school schedule from a web file (e.g., HTML) saved locally.
Format Conversion: The application converts the imported schedule into the .ics format, compatible with popular calendar applications like iCalendar and Google Calendar.
User Interaction: The program provides a user-friendly interface with clear instructions for importing the schedule and exporting the converted .ics file.
Customization: Users have the option to customize certain parameters, such as the file path for the imported schedule and the output directory for the .ics file.
Error Handling: The application includes input validation and error handling to ensure the integrity of the converted schedule.
Flexibility: The program allows users to control the flow of the conversion process, offering flexibility in how the schedule is processed and converted.

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
