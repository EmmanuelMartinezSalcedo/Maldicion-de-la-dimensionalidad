import subprocess
import os

cpp_executable = 'distance-generator.exe'
subprocess.run([cpp_executable])

notebook_file = 'graphics.ipynb'
subprocess.run(['jupyter', 'nbconvert', '--to', 'notebook', '--execute', notebook_file])