let canvasMiddleware = (reducer: Types.reducer) => {
  let (action: Types.action, state: Types.state) = reducer;
  let newState =
    switch (action) {
    | MouseUp(x, y) => {...state, count: state.count + 1}
    | MouseMove(x, y) => {...state, show: ! state.show}
    | MouseDown(x, y) => {...state, show: ! state.show}
    };
  (action, newState);
};