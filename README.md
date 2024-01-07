# NCPP Lite
NCoder's Game Engine Learning Aimed C++ Library.

---

## Features
+ Memory management:
  + Incremental chunk allocator
  + **Smart chunk allocator**
    + **⚠️ Warning**: `not avaiable on NCPP Lite Distribution`
  + Reference allocator
  + **Powerful allocator base class**
+ Containers:
  + EASTL containers (typedefs)
  + Ring buffer (both concurrent and non-concurrent versions)
  + Hash table (like Unreal Engine's one)
  + **Container view** (constant container reference)
+ Logging:
  + String
  + Vector
  + Array
  + Initialier_list
  + **Convenient coloring**
  + ...
+ Utilities:
  + **Magic type syntax** for both variables and functions: `(F_returns...)(F_arguments...)`
  + **Constant pass** (optimized constant variable passing)
  + N-th template argument getter
  + Function traits
  + Is derived from checker
  + Is streamable
  + Singleton
  + Type info
  + ...
+ RTTI (Runtime-Type Information):
  + Type flag
  + Subtype
  + **Reflection**
    + **⚠️ Warning**: `not avaiable on NCPP Lite Distribution`
    + Easy to use
    + No additional memory cost on reflected object
    + Metadata supports 
    + Fast compilation
    + Flexible and highly customizable

---

## Core Dependencies
+ EASTL
+ Doxygen (Optional)

---

## Supported Platforms
  + Windows
  + MacOS
  + Unix Platforms

---

## Supported IDEs and Text Editors (for scripts)
  + Visual Studio
  + Xcode
  + CLion
  + Visual Studio Code

---

## Building
  + **Visual Studio 2022** (Windows):
    + Step 1: Clone [NCPP Lite git repository](https://github.com/n-c0d3r/NCPPLite) from GitHub
    + Step 2: Generate Visual Studio 2022 solution by running **scripts/generate_vs2022.bat**
    + Step 3: Navigate to **build/vs2022**
    + Step 4: Open **npp.sln**
    + Step 5: Set **ncpp.samples.hello_ncpp** as startup project
    + Step 6: Run and enjoy!
  + **Xcode** (MacOS):
    + Step 1: Clone [NCPP Lite git repository](https://github.com/n-c0d3r/NCPPLite) from GitHub
    + Step 2: Generate Xcode solution by running **scripts/generate_xcode.sh**
    + Step 3: Navigate to **build/xcode**
    + Step 4: Open **ncpp.xcodeproj**
    + Step 5: Choose **ncpp.samples.hello_ncpp** for current scheme
    + Step 6: Run and enjoy!
  + **CLion** (Windows, MacOS, Linux):
    + Step 1: Clone [NCPP Lite git repository](https://github.com/n-c0d3r/NCPPLite) from GitHub
    + Step 2: Open CLion by running one of these scripts based on your environment (you may need to use chmod +x command first on Linux and MacOS for execute permission):
      + Windows
        + **scripts/python_open_clion.bat**
        + **scripts/python3_open_clion.bat**
      + MacOS, Linux:
        + **scripts/python_open_clion.sh**
        + **scripts/python3_open_clion.sh** 
    + Step 3: At **On Project Wizard**, click "OK" (if you dont see it, dont worry, go to the next step).
    + Step 4: Run and enjoy!
  + **Unix makefiles**:
    + Step 1: Clone [NCPP Lite git repository](https://github.com/n-c0d3r/NCPPLite) from GitHub
    + Step 2: Generate makefiles by running **scripts/generate_unix_makefiles.sh**
    + Step 3: execute **scripts/build_unix_makefiles.sh** to build project
    + Step 4: Navigate to **build/unix_makefiles/ncpp/samples/hello_ncpp**
    + Step 5: Run "ncpp.samples.hello_ncpp" and enjoy!

---

## License
+ NCPP Lite is licensed under the [MIT License](https://github.com/n-c0d3r/NCPPLite/blob/main/LICENSE)
