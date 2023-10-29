<p align="center"><img src=".github/assets/cursusbanner.png" alt="Cursus banner"/></p>

Welcome to my 42Cursus repository! This is where I'll be sharing all the projects I work on during my time as a student in 42Malaga.

The purpose of this repository is to keep track of my journey as a coding student at 42. Here, you'll find the projects I develop as part of my 42 experience. 

**Important Note:** This repository is continuously updated as I progress through each project, which means that the latest proyects may be unfinished or have important errors (check the status of each proyect on [Proyects](#proyects)). 

Feel free to explore the repo, provide feedback, and follow along!

**Important Notice:** ⚠️ This repository is intended as a learning resource and to keep track of my personal progress. While I encourage you to use it to enhance your understanding and skills, it's crucial to understand that copying or using this code inappropriately for presenting your 42 personal projects can lead to a cheating grade. Moreover, copying code won't help your academic growth, which is why I highly discourage you to do it.
## Projects

<table>
   <thead>
      <th>Projects</th>
      <th>Legend</th>
   </thead>
   <tbody>
      <tr><td>
            <table>
               <tr>
                  <td>Level 0</td>
                  <td><a href="https://github.com/jandrana/libft"><img src=".github/assets/libftm.png" alt="libft bonus" width="90"/></a></td>
               </tr>
               <tr>
                  <td>Grade:</td>
                  <td align="center">125/100</td>
               </tr>
               <tr align="center">
                  <td>Submission:</td>
                  <td><a href="https://github.com/jandrana/libft">18/09/2023</a></td>
               </tr>
            </table>
            <table>
               <tr>
                  <td>Level 1</td>
                  <td><a href="https://github.com/jandrana/ft_printf"><img src=".github/assets/ft_printfe.png" alt="printf" width="95"/></a></td>
                  <td><a href="https://github.com/jandrana/get_next_line"><img src=".github/assets/get_next_linem.png" alt="get_next_line bonus" width="90"/></a></td>
                  <td><a href=""><img src=".github/assets/born2berootm.png" alt="born2beroot bonus" width="90"/></a></td>
               </tr>
               <tr>
                  <td>Grade:</td>
                  <td align="center">100/100</td>
                  <td align="center">125/100</td>
                  <td align="center">125/100</td>
               </tr>
               <tr align="center">
                  <td>Submission:</td>
                  <td><a href="https://github.com/jandrana/ft_printf">25/09/2023</a></td>
                  <td><a href="https://github.com/jandrana/get_next_line">02/10/2023</a></td>
                  <td>17/10/2023</td>
               </tr>
            </table>
            <table>
               <tr>
                  <td>Level 2</td>
                  <td align="center">Exam Rank<br>02</td>
                  <td><a href=""><img src=".github/assets/push_swapn.png" alt="push_swap in progress" width="90"/></a></td>
               </tr>
               <tr>
                  <td>Grade:</td>
                  <td align="center">100/100</td>
                  <td rowspan="2" align="center">❓</td>
               </tr>
               <tr align="center">
                  <td>Submission:</td>
                  <td>19/10/2023</td>
               </tr>
            </table>
      </td>
      <td>
         <table>
            <thead>
               <th colspan="4">Badge Colours</th>
            </thead>
            <tbody>
               <tr>
                  <td><strong>Color</strong></td>
                  <td><strong>Status</strong></td>
                  <td><strong>Example</strong></td>
               </tr>
               <tr align="center">
                  <td>⚫️</td>
                  <td>In progress</td>
                  <td><img src=".github/assets/inprogress.png" alt="in progress" width="70"/></td>
               </tr>
               <tr align="center">
                  <td>🔵</td>
                  <td>Finished</td>
                  <td><img src=".github/assets/finished.png" alt="completed" width="70"/></td>
               </tr>
               <tr align="center">
                  <td>⭐️</td>
                  <td>Finished<br>with bonus</td>
                  <td><img src=".github/assets/bonus.png" alt="completed bonus" width="68"/></td>
               </tr>
            </tbody>
         </table>
      </td></tr>
   </tbody>
</table>

## Project Descriptions

### Level 0: [libft](https://github.com/jandrana/libft)

The `libft` project is the first one of my journey as a 42 student and has played a crucial role in upcoming assignments, since the library created here is used in upcoming projects. Here, I created my very first C library from scratch.

This project pushed me to deeply understand how the original replicated functions work, helping me develop a more comprehensive understanding of their inner workings and how to enhance them. It's not just about meeting project requirements; it's about making the best possible library since it will become the base of many other projects.

### Level 1: [ft_printf](https://github.com/jandrana/ft_printf)

In the `ft_printf` project, I replicated the functionality of the standard `printf` function in C. The main challenge of this project was to learn how variadic functions work and how to use them, which involved handling the formatting and printing of text with different data types. Completing this project made possible adding it to my "libft" library for future use.

### Level 1: [get_next_line](https://github.com/jandrana/get_next_line)

The `get_next_line` project focuses on developing a function that reads content from a file descriptor line by line. With this project I got the opportunity to really understand how to prevent memory leaks and how to allocate just the neccessary space in order to increase the optimization of the code. Furthermore, with the bonus files, not only you can read content from one but from as many file descriptor as you want without losing track of what line you have to return next.

### Level 1: born2beroot

With the `born2beroot` proyect I learned to create and configure a VM with Debian (without graphical interface). After installing the VM I got to install and configure the following programs/services: sudo (including commands logs), ssh, ufw, wordpress (mariadb, php, openlitespeed). The project also included the development of a sh script that showed general information of the virtual machine every 10 minutes. Information like: VM architecture, RAM load, CPU load, ip and MAC address, number of: vCPU, TCP connections, sudo commands done...

In the following days I will upload a series of screenshots of my born2beroot and some more explanations.

## Usage

This repository is intended for academic and educational purposes. It is meant to showcase my progress as a student in the 42Cursus. Please use it responsibly.

### Testing the Projects

To test the projects in this repository, you'll need access to a compatible development environment. The following instructions provide a general guideline:

1. **Operating System Compatibility:** The projects in this repository are primarily designed for Unix-like operating systems. It is recommended to use macOS or a Linux distribution (e.g., Ubuntu) for optimal compatibility.

2. **Prerequisites:** Ensure that you have the necessary tools and compilers installed, such as `gcc` for C projects. You may also need specific libraries or dependencies, which will be documented within each project's directory.

3. **Compilation:** Check if the project you want to compile contains a Makefile. If there's a Makefile present, navigate to the project's directory and use the `make` command to build it. If there is no Makefile, compile as preferred. For example:

   ```bash
   cd project_folder
   make

Please note that these are general guidelines, and each project may have its own specific setup and testing requirements. Check on the project's individual README for detailed instructions on how to test the project.
## Feedback

I warmly welcome feedback and contributions to this repository. If you find any issues, have suggestions for improvements, or would like to collaborate, please don't hesitate to reach out.

- You can [open an issue](https://github.com/jandrana/42-Cursus/issues) to report problems or propose enhancements.
- Additionally, feel free to [contact me](#contact-me) directly if you have any questions or ideas to share.

## Contact me

- Github: [@jandrana](https://github.com/jandrana)
- 42 login: [ana-cast](https://profile.intra.42.fr/users/ana-cast)
- Mail: yo@anaalejandra.com

Feel free to contact me!
## Acknowledgments

I would like thank all the following individuals and resources who have contributed to the development of the projects in this repository:

- The 42 Students Community: I would like to thank to all the 42 students who have supported and guided from my very first day in 42Malaga.

- [Francinette](https://github.com/xicodomingues/francinette): A comprehensive project tester that helped ensure the robustness of my code.

- [42make](https://github.com/Nimon77/42make): An inspiration and reference for creating efficient Makefiles for my projects.

- [ASCII Art Generator](https://patorjk.com/software/taag/#p=testall&c=echo&f=Arrows&t=ft_printf): A helpful online tool for creating stylish headers and drawings for the Makefiles.
