import subprocess

# Ejecutar el programa C++
cpp_executable = 'distance-generator.exe'
subprocess.run([cpp_executable])

# Ejecutar el cuaderno de Jupyter usando Python como módulo
notebook_file = 'graphics.ipynb'
subprocess.run(['python', '-m', 'notebook', notebook_file])
