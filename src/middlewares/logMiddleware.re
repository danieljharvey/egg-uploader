let logMiddleware: Types.middleware =
  reducer => {
    let (action, state) = reducer;
    Js.log3("LOG", state, action);
    reducer;
  };