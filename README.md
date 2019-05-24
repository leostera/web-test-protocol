# Web Test Protocol
> Just a simple testing protocol that I used for a presentation.

<img src="./web-test-protocol.png" width="250" />

Testing is a necessity. We test by writing functions that evaluate our
application, and either fail or succeed. We group these functions together, and
we execute them serially or in parallel, exporting these results in different
formats.

This small document defines some common vocabulary for describing tests, and
a set of steps to execute them.

## Vocabulary

A _test result_ is a value that indicates whether the test was successfull or
if it failed. If it failed, an error message should be provided for clarity.

A _test_ is a function with an associated name, that will return a _test result_.

A _suite_ is a list of _tests_ with an associated description.

## Running Tests

Evaluating a _suite_ takes all the tests in the suite, and one at a time it
executes a test.

The algorithm, in pseudocode, is:

```
RUN SUITE S:
  FOR EVERY TEST IN S’ TESTS
    RUN TEST
    IF TEST IS SUCCESSFUL
      SAVE SUCCESSFUL RESULT
    ELSE
      SAVE FAILED RESULT
```
