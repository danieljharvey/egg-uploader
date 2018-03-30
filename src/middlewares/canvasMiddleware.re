/* this reducer cares about drawing boxes on a picture and nothing else */
let canvasMiddleware = (reducer: Types.reducer(Types.action, Types.state)) => {
  let (action: Types.action, state: Types.state) = reducer;
  switch (action) {
  | MouseUp(x, y) => {...state, endCoord: Some({x, y})}
  | MouseMove(x, y) => {...state, endCoord: Some({x, y})}
  | MouseDown(x, y) => {...state, startCoord: Some({x, y}), endCoord: None}
  };
};