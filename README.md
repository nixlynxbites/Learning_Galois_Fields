# Working Repository

This is a repository for working on the problems and exercises found here https://xorvoid.com/galois_fields_for_great_good_00.html

# Dependencies

The Tests use utest.h (https://github.com/sheredom/utest.h) Commit 97236c14007916ebb4522d7e7290c242cc372d41  
utest.h has been slightly patched, so it will build even if custom types are used with it  
(The Patch is a Hack that just ifdefs out the failing parts)

# Building

First cd into the Exercise folder you want to build

For building the Tool to play around with it
```
make build
./GFTool
```
For building and running the tests
```
make test
./GFTest
```


# Licensing

utest.h is licensed under The Unlicense (see: https://github.com/sheredom/utest.h/blob/master/LICENSE)  
Everything else in this repository is licensed under EUPL V1.2

# Disclaimer

This code isn't written to be good code, but to test and understand the concepts. Therefore, shortcuts have been taken, to easily/quickly test/do things. (This includes the Makefiles)
