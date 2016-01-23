
void
print_usage (void)
{
  printf ("-h, --help\n");
  printf ("-c, --config filename     use an alternate configuration\n");
  printf ("-l, --list                list waste directories\n");
  printf
    ("-a, --add-waste dir       add waste directory to configuration file\n");
  printf ("-p, --pause               wait for a keypress before exiting\n");
  printf
    ("-g, --purge               run purge even if it's been run today\n");
  printf ("-z, --restore <wildcard filename(s) pattern>\n");
  printf ("-s, --select              select files from list to restore\n");
  printf ("-u, --undo-last           undo last ReMove\n");
  printf ("-B, --bypass              bypass directory protection\n");
  printf ("-v, --verbose             increase output messages\n");
  printf ("-w, --warranty            display warranty\n");
  printf
    ("-V, --version             display version and license information\n");
}



void
warranty (void)
{
  printf
    ("THERE IS NO WARRANTY FOR THE PROGRAM, TO THE EXTENT PERMITTED BY\n");
  printf
    ("APPLICABLE LAW.  EXCEPT WHEN OTHERWISE STATED IN WRITING THE COPYRIGHT\n");
  printf
    ("HOLDERS AND/OR OTHER PARTIES PROVIDE THE PROGRAM \"AS IS\" WITHOUT WARRANTY\n");
  printf
    ("OF ANY KIND, EITHER EXPRESSED OR IMPLIED, INCLUDING, BUT NOT LIMITED TO,\n");
  printf
    ("THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR\n");
  printf
    ("PURPOSE.  THE ENTIRE RISK AS TO THE QUALITY AND PERFORMANCE OF THE PROGRAM\n");
  printf
    ("IS WITH YOU.  SHOULD THE PROGRAM PROVE DEFECTIVE, YOU ASSUME THE COST OF\n");
  printf ("ALL NECESSARY SERVICING, REPAIR OR CORRECTION.\n");
  exit (0);
}

void
version (void)
{

  printf ("rmw %s\n", VERSION);
  printf ("Author: Andy Alt (andyqwerty@users.sourceforge.net)\n");
  printf
    ("This program comes with ABSOLUTELY NO WARRANTY; for details type 'rmw -w.'\n");
  printf ("This is free software, and you are welcome to redistribute it\n");
  printf
    ("under certain conditions; see <http://www.gnu.org/licenses/gpl.html>\n");
  printf ("for details.\n");
  exit (0);
}
