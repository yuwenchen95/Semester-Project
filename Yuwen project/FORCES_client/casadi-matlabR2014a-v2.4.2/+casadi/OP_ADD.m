function v = OP_ADD()
  persistent vInitialized;
  if isempty(vInitialized)
    vInitialized = casadiMEX(0, 64);
  end
  v = vInitialized;
end
