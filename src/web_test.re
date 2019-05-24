module Test = {
  type status =
    | Successful
    | Failed(string);

  type t = {
    name: string,
    f: unit => status,
  };

  type test_result = {
    test: t,
    status,
  };
};

module Suite = {
  type t = {
    description: string,
    tests: list(Test.t),
  };

  type results = {
    description: string,
    results: list(Test.test_result),
  };
};

let run_test: Test.t => Test.test_result = test => {test, status: test.f()};

let run_suite: Suite.t => Suite.results =
  suite => {
    {
      description: suite.description,
      results: suite.tests |> List.map(run_test),
    };
  };
