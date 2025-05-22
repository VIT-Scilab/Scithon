This toolbox embeds Python in Scilab, allowing the use of python data and python modules, both standard and non standard, in scilab

### Requirements

- **Operating System**: Windows 10 or any Linux distribution (64-bit)
- **Scilab Version**: 2025.0.0
- **Python**:
    - Linux: Any Python version along with the header files (`python3-dev` package on Debian based distros)
    - Windows: Python 3.13
- **MSVC Compiler**: Required for building on Windows

### Building Instructions (Linux)

1. Install Scilab.
2. Download the toolbox source code from github repository or Scilab atoms.
3. Ensure Python is installed and run the `setup.py` script from the git repository to configure the environment.
    ```bash
    cd YOUR_FOLDER/Scithon
    python3 setup.py
    ```
4. Open builder.sce file in the source code and execute the same.
5. Refer to the help files to understand the usage of toolbox functionalities.

### Building Instructions (Windows)

1. Install Scilab.
2. Download the toolbox source code from github repository or Scilab atoms.
3. Open builder.sce file in the source code and execute the same.
4. Refer to the help files to understand the usage of toolbox functionalities.

### Frequestly Asked Questions

1. I have python 3.13 installed, but the toolbox still says user installation not found

    i) Try restarting Scilab

    ii) Try restarting your device

    iii) Try setting Python 3.13 as the default python interpreter

---

2. How do I install and use external modules ?

    You need to install python 3.13 externally and install the modules you wish to use through pip externally.
    You will be able to use all the user installed modules just like the standard ones.

---

3. How do I use the Python's builtin functions like range or complex ?

    You can import the 'builtins' module and call the functions off of that.  
    startPy  
    Py = pyImport("builtins")  
    x = Py.range(10, 20)  
    y = Py.complex(1, 2)  
    quitPy

---

4. How do I set or change the values of elements in sequence objects like list, tuple and set, or mapping based objects like dictionary ?

    You can change the value of a specific index or key by passing the new value along with the index or key.  
    For example, if x is a list [1,2,3], then you would change the element at index 1 to 5 in this way.  
    x(1, 5)  
    If y is a dictionary {"one": 1, "two": 3, "three": 3}, then you would change the element with key "two" to 2 in this way.  
    y("two", 2)

---

5. How do I set or change the values of attributes of an object ?

    You can change the values of attributes, by passing the name of the attribute as a string and the new value, similar to dicitonary.  
    For example, this is how you can set the value of pi in the math module to 3.  
    startPy  
    math = pyImport("math")  
    disp(math.pi)  
    math("pi", 3)  
    disp(math.pi)  
    quitPy

---

6. How do I use Python's plotting functions ?

    Unfortunately, plotting is not possible using Python functions.  
    Consider using py2sci to convert your python data to scilab data and then using the Scilab plotting functions.

---

7. How do I pass keyword arguments to functions?

    Unfortunately, you cannot pass keyword arguments.  
    This feature may be added in a future update.

---

This toolbox was made entirely by students of Vellore Institute of Technology, Chennai  
Students involved in the making of the toolbox:

- Jishnu
- Adrian Nirmal Andrew
- Adityan Sunil Kumar
- Dheekksha R
- Aakash Ezhilan
- Mahesh

Toolbox was built under the supervision of Dr. T. Subbulakshmi  
Acknowledgement: Dr. Kannan Mani Moudgalya, Free/Libre and Open Source Software for Education, IIT Bombay, Govt. of India

If you have any queries, email us at vitscope.scilab@gmail.com
