let canvasMiddleware = (reducer: Types.reducer) => {
  let (action: Types.action, state: Types.state) = reducer;
  let newState =
    switch (action) {
    | MouseUp(x, y) => {...state, endCoord: Some({x, y})}
    | MouseMove(x, y) => {...state, endCoord: Some({x, y})}
    | MouseDown(x, y) => {startCoord: Some({x, y}), endCoord: None}
    };
  (action, newState);
};