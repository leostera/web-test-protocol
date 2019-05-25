module Test = {
  type test_result =
    | Success
    | Failure(string);

  type t = {
    name: string,
    f: unit => test_result,
  };
};

module Suite = {
  type t = {
    description: string,
    tests: list(Test.t),
  };
};

let run_suite: Suite.t => list(Test.test_result) =
  suite => {
    suite.tests |> List.map(t => Test.(t.f()));
  };
