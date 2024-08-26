project('dsa', 'cpp')
c = run_command('./get_sources.sh', check: true)
src = c.stdout().strip().split('\n')

inc_dir = include_directories('include')
executable('dsa', src, include_directories: inc_dir)
