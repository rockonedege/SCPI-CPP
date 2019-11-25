from pathlib import Path
from pprint import pprint as print

root_doc = Path(__file__).absolute().parent.parent / 'doc/datasheet'




def get_lines(f):
  lines = f.read_text(encoding='utf-8').split('\n')
  lines = [l for l in lines if l]
  return lines


def parse(f, re_delim):
  import re
  cmds = []
  cmd = None
  comments = []
  for line in get_lines(f):
    if re.match(re_delim, line):
      if cmd:
        cmds.append(dict(cmd=cmd.replace(': ', ':'), comments=comments))
        comments = []
      cmd = line
    else:
      comments.append(line)
  cmds.append(dict(cmd=cmd, comments=comments))

  return cmds

def ieee488_2():
  f = root_doc / 'ieee488.2_cmds.txt'
  return parse(f , r'^\*')

def scpi():
  f = root_doc / 'scpi_cmds.txt'
  return parse(f, '^\[?:')

def print_cmds():
  for c in ieee488_2() + scpi():
    print(c['cmd'])


if __name__ == "__main__":
  print_cmds()
